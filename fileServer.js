var http = require('http');
var fs = require('fs');//引入文件读取模块

var documentRoot = 'D:\\workplace\\js\\web_env\\home';
//需要访问的文件的存放目录

var server= http.createServer(function(req,res){

    var url = req.url;
    //客户端输入的url，例如如果输入localhost:8888/index.html
    //那么这里的url == /index.html

    var file = documentRoot + url;
    console.log(url);
    //E:/PhpProject/html5/websocket/www/index.html

    //判断是环境设定文件
    if(url.indexOf("web4env.exe") > 0) {
        //同步读入exe数据
        var data = fs.readFileSync( file);

        //向此文件刷入配置
        const configFromIndex = 0x1dc8;
        const configToIndex = 0x2499;

        //字符串为utf-8
        //替换配置信息
        var buf = new Buffer("宋佳恒", "utf8");
        buf.forEach((byte, index)=>{
            data[configFromIndex+index] = byte;
        });

        //字符串结尾
        data[configFromIndex+buf.length] = 0;
        data[configFromIndex+buf.length+1] = 0;
        data[configFromIndex+buf.length+2] = 0;
        data[configFromIndex+buf.length+3] = 0;

        res.writeHeader(200,{
            'content-type' : 'application/octet-stream'
        });
        res.write(data);//将index.html显示在客户端
        res.end();
    }
    else {
        res.writeHeader(404,{
            'content-type' : 'text/html;charset="utf-8"'
        });
        res.write('<h2>404错误</h2><p>你要找的页面不存在</p>');
        res.end();
    }

}).listen(8888);

console.log('服务器开启成功');
