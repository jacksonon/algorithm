var fs = require("fs");
const { exec } = require('child_process');
var count = 0;

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
            var inputfile = "\n"+ "- " + '[' + file + ']' + '(https://github.com/wang542413041/algorithm/blob/master/' + file + ')' ;
            fs.appendFileSync(fileName, inputfile);
	    count += 1;
        }
    });
    var date1 = new Date('2020/5/19 0:0:0');    //开始时间
    var date2 = new Date();    //结束时间
    var date3 = date2.getTime() - date1.getTime(); //时间差秒
    var days = Math.floor(date3/(24*3600*1000));
    var tims = '\n > ' + '累计答题 : ' + days + '天    ' + '总数 : ' + count + '题';
    fs.appendFileSync(fileName, tims);
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
