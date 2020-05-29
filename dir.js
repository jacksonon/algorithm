var fs = require("fs");
const { exec } = require('child_process');

let fileName = 'README.md'

// cover read me file
fs.writeFile(fileName, '# 小学生进阶之路\n', function(err){
    if (err) {
        console.log(err);
    }
});

fs.readdir("./", function(err, files) {
    if (err) {
        return console.error(err);
    }
    files.forEach(function(file) {
        if (file.indexOf('.cpp') != -1 || file.indexOf('.swift') != -1) {
            var inputfile = "\n"+ "- " + file;
            fs.appendFileSync(fileName, inputfile);
        }
    });
});

var buf = new Buffer.alloc(1024);
fs.open(fileName, 'r+', function(err, fd) {
    if (err) {
        return console.log(err);
    }
    fs.read(fd, buf, 0, buf.length, 0, function(err, bytes) {
        if (bytes > 0 && !err) {
            console.log(buf.slice(0, bytes).toString());
        }
    });
});