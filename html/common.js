var context;
// 初始化
function init() {
    if (typeof qt != 'undefined') {
        new QWebChannel(qt.webChannelTransport, function (channel) {
            context = channel.objects.context;
        }
        );
    }
    else {
        alert("qt对象获取失败！");
    }
}
// 向qt发送消息
function sendMessage(msg) {
    if (typeof context == 'undefined') {
        alert("context对象获取失败！");
    }
    else {
        context.onMsg(msg);
    }
}

function recvMessage(msg) {
    var textarea = document.getElementById("comments");
    textarea.innerHTML += ("Qt say : " + msg + "\n");
}

// 控件控制函数
function onBtnSendMsg() {
    var cmd = document.getElementById("message").value;
    sendMessage(cmd);
}

var btn = document.getElementById("btn");
btn.addEventListener("click", onBtnSendMsg);
init();