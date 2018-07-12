var serialport = require('serialport');
var port = new serialport('COM4', {
    baudRate: 9600,
});

var d = "";
port.on('data', function (data) {
    data = data.toString();
    for(var i = 0; i < data.length; i++) {
        d += data[i];
        if(data[i] == '\n') {
            //chop
            var chunk = d.trim().split(",");
            d = '';
            if(chunk.length != 2) {
                continue;
            }
            var all = chunk.map((v) => {
                return parseFloat(v.trim());
            });
            console.log(all);
        }
    }
});