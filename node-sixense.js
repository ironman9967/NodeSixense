
var util = require('util');
var events = require('events');

var _ = require('lodash');

var sixense = require('./build/Release/sixense');

function NodeSixense() {
	if (this instanceof NodeSixense === false) {
		return new NodeSixense();
	}
	events.EventEmitter.call(this);
	_.extend(this, sixense);
	this._setupEvents();
}
util.inherits(NodeSixense, events.EventEmitter);

NodeSixense.prototype._setupEvents = function () {
	var instance = this;
	this.on('getAllNewestData', function (callback) {
		instance.sixenseGetAllNewestDataAsync(callback);
	});
	this.on('stopGetAllNewestData', function (callback) {
		instance.sixenseGetAllNewestDataAsyncStop();
		callback();
	});
};

//NodeSixense.prototype.emit = function () {
//	if (arguments.length >= 2) {
//		var eventName = arguments[0];
//		if (eventName !== "removeListener") {
//			var eventArguments = arguments.length === 2 ? [] : _.initial(_.rest(_.toArray(arguments), 1));
//			var callback = arguments[arguments.length - 1];
//			var sdkMethodName = "sixenseGet" + CapFirstLetter(eventName) + "Async";
//			var sdkMethod = this[sdkMethodName];
//			if (sdkMethod !== void 0) {
//				var instance = this;
//				sdkMethod.apply(this, eventArguments.concat([ function (error, data) {
//					instance.emit(eventName, error, data);
//				} ]));
//			}
//			else {
//				callback(new Error(sdkMethodName + " not found"));
//			}
//		}
//	}
//	else {
//		throw new Error("bad signature, should be -> emit(eventName, ...eventArgs, " +
//			"function callback(error, data)");
//	}
//};

var nodeSixense = new NodeSixense();

//nodeSixense.on('newListener', function () {
//	var instance = this;
//	var eventName = arguments[0];
//	if (eventName !== "removeListener") {
//		var eventArguments = _.toArray(arguments);
//		var callback = arguments[1];
//
//		console.log(eventArguments);
//
////		var sdkMethodName = "sixenseGet" + CapFirstLetter(eventName) + "Async";
////		var sdkMethod = instance[sdkMethodName];
////		if (sdkMethod !== void 0) {
////			sdkMethod(function (error, data) {
////				instance.emit(eventName, error, data);
////			});
////		}
////		else {
////			callback(new Error(sdkMethodName + " not found"));
////		}
//	}
//});
//nodeSixense.on('removeListener', function () {
//	var instance = this;
//	var eventName = arguments[0];
//	if (eventName !== "newListener") {
//		var sdkMethodName = "sixenseGet" + CapFirstLetter(eventName) + "AsyncStop";
//		var sdkMethod = instance[sdkMethodName];
//		if (sdkMethod !== void 0) {
//			sdkMethod();
//		}
//		else {
//			callback(new Error(sdkMethodName + " not found"));
//		}
//	}
//});

module.exports = nodeSixense;

function CapFirstLetter(str) {
	return str.substring(0, 1).toUpperCase() + str.substring(1);
}