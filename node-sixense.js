
var util = require('util');
var events = require('events');

var sixense = require('./build/Release/sixense');

function NodeSixense() {
	if (this instanceof NodeSixense === false) {
		return new NodeSixense();
	}
	events.EventEmitter.call(this);
	this.sixenseSDK = sixense;
}
util.inherits(NodeSixense, events.EventEmitter);

var nodeSixense = new NodeSixense();

var intervals = {};

nodeSixense.on('newListener', function (eventName) {
	var instance = this;
	if (eventName !== "removeListener") {
		var sdkMethod = instance.sixenseSDK["sixenseGet" + CapFirstLetter(eventName) + "Async"];
		if (sdkMethod !== void 0) {
			intervals[eventName] = setInterval(function () {
				sdkMethod(function (error, data) {
					instance.emit(eventName, error, data);
				});
			}, 16.6);
		}
	}

});
nodeSixense.on('removeListener', function (eventName) {
	if (eventName !== "newListener") {
		clearInterval(intervals[eventName]);
	}
});

module.exports = nodeSixense;

function CapFirstLetter(str) {
	return str.substring(0, 1).toUpperCase() + str.substring(1);
}