var context;
// ��ʼ��
function init() {
    if (typeof qt != 'undefined') {
        new QWebChannel(qt.webChannelTransport, function (channel) {
            context = channel.objects.context;
        }
        );
    }
    else {
        alert("qt�����ȡʧ�ܣ�");
    }
}
// ��qt������Ϣ
function sendMessage(msg) {
    if (typeof context == 'undefined') {
        alert("context�����ȡʧ�ܣ�");
    }
    else {
        context.onMsg(msg);
    }
}

function recvMessage(msg) {
    var textarea = document.getElementById("comments");
    textarea.innerHTML += ("Qt say : " + msg + "\n");
}

// �ؼ����ƺ���
function onBtnSendMsg() {
    var cmd = document.getElementById("message").value;
    sendMessage(cmd);
}

var btn = document.getElementById("btn");
btn.addEventListener("click", onBtnSendMsg);
init();