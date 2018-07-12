var serialport = require('serialport');
var port = new serialport('COM4', {
    baudRate: 9600,
});

var d = "";
port.on('data', function (data) {
    d += data.toString();
    d = d.trim();
    if (d.indexOf("\n") >= 0) {
        var chunk = d.split("\n")[0];
        d = d.substring(chunk.length);
        if (chunk.split(",").length != 2) {
            return;
        }
        var all = chunk.split(",").map((v) => {
            return parseFloat(v.trim());
        });
        console.log(all);
    }
});