
var util = require('util');
var events = require('events');

var _ = require('lodash');
var async = require('async');

var sixense = require('./build/Release/sixense');

function NodeSixense() {
	if (this instanceof NodeSixense === false) {
		return new NodeSixense();
	}
	events.EventEmitter.call(this);
	_.extend(this, sixense);
}
util.inherits(NodeSixense, events.EventEmitter);

var nodeSixense = new NodeSixense();

var syncing = false;
var currentAllData = void 0;
var previousAllData = void 0;

nodeSixense.on('newListener', function (eventName) {
	if (eventName !== "removeListener") {
		if (!syncing) {
			syncing = true;
			var instance = this;
			this.sixenseGetAllNewestDataAsync(function (error, data) {
				if (error === void 0) {
					previousAllData = currentAllData === void 0 ? data : currentAllData;
					currentAllData = data;
					var metaData = {
						sequenceNumber: currentAllData.sequenceNumber,
						firmwareRevision: currentAllData.firmwareRevision,
						hardwareRevision: currentAllData.hardwareRevision,
						packetType: currentAllData.packetType,
						magneticFrequency: currentAllData.magneticFrequency,
						enabled: currentAllData.enabled,
						controllerIndex: currentAllData.controllerIndex,
						isDocked: currentAllData.isDocked,
						whichHand: currentAllData.whichHand,
						hemisphereTrackingEnabled: currentAllData.hemisphereTrackingEnabled
					};
					var listeners = _.keys(_.omit(instance._events, 'newListener', 'removeListener'));
					async.each(listeners, function (eventKey, callback) {
						var eventData =
							getEventKeyChainData(eventKey.split(":"), currentAllData, previousAllData);
						var callEvent = eventData !== void 0 && instance._events[eventKey] !== void 0
							&& typeof instance._events[eventKey] === "function";
						if (callEvent) {
							instance._events[eventKey](eventData, metaData);
						}
						callback();
					}, function (asyncError) {
						if (asyncError !== void 0 && asyncError !== null) {
							throw asyncError;
						}
					});
				}
				else {
					this.sixenseGetAllNewestDataAsyncStop();
					syncing = false;
					throw error;
				}
			});
		}
	}
});
function getEventKeyChainData(eventKeyChain, current, previous) {
	var eventData = void 0;
	var currentEventKey = eventKeyChain.shift();
	switch (currentEventKey) {
		case 'controller':
			var index = eventKeyChain.shift();
			if (eventKeyChain.length === 0) {
				eventData = current[index];
			}
			else {
				return getEventKeyChainData(eventKeyChain, current[index], previous[index]);
			}
			break;
		default:
			if (eventKeyChain.length === 0) {
				if (currentEventKey === "trigger") {
					if (current[currentEventKey] !== previous[currentEventKey]) {
						eventData = {
							trigger: current[currentEventKey]
						};
					}
				}
				else {
					eventData = current[currentEventKey];
				}
			}
			else if (eventKeyChain.length === 1) {
				var currentData = current[currentEventKey][eventKeyChain[0]];
				if (currentData !== previous[currentEventKey][eventKeyChain[0]]) {
					eventData = {};
					eventData[eventKeyChain[0]] = currentData;
				}
			}
			else {
				return getEventKeyChainData(eventKeyChain, current[currentEventKey],
					previous[currentEventKey]);
			}
	}
	return eventData;
}
nodeSixense.on('removeListener', function (eventName) {
	if (eventName !== "newListener") {
		if (_.every(_.keys(this._events), function (eventKey) {
			return eventKey === "removeListener" || eventKey === "newListener";
		})) {
			this.sixenseGetAllNewestDataAsyncStop();
			syncing = false;
		}
	}
});

module.exports = nodeSixense;