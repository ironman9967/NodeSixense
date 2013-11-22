
var sixense = require('./build/Release/sixense');

sixense.sixenseInit();
sixense.sixenseSetActiveBase(0);

//console.log(sixense.sixenseGetMaxBases());
//console.log(sixense.sixenseIsBaseConnected(0));
//console.log(sixense.sixenseGetMaxControllers());
//console.log(sixense.sixenseGetNumActiveControllers());
//console.log(sixense.sixenseIsControllerEnabled(0));
var interval = setInterval(function () {
	var allData = sixense.sixenseGetAllNewestData();
	for (var i = 0; i < 4; i++) {
		var con = allData[i];
		if (con.enabled) {
			console.log(con);
		}
	}
}, 2000);

setTimeout(function () {
	clearInterval(interval);
	setTimeout(function () {
		sixense.sixenseExit();
	}, 500);
}, 90000);

function round(number, numberOfDecimals) {
	if (numberOfDecimals === undefined) {
		numberOfDecimals = 5;
	}
	var result = undefined;
	if (numberOfDecimals > 0) {
		var pow = Math.pow(10, numberOfDecimals);
		result = Math.round(number * pow) / pow;
	}
	else {
		result = Math.round(number);
	}
	return result;
}
