var checkAll = document.getElementById('selectAll');
var unCheck = document.getElementById('selectNone');
var revertCheck = document.getElementById('selectRevert');
var div = document.getElementById('items');
var checkBox = div.getElementsByTagName('input');

checkAll.onclick = function(){
    for(i=0;i<checkBox.length;i++){
        checkBox[i].checked = true;
    }
}

unCheck.onclick = function(){
    for(i = 0;i < checkBox.length;i++){
        checkBox[i].checked = false;
    }
}

revertCheck.onclick = function(){
    for(i = 0;i < checkBox.length;i++){
        if(checkBox[i].checked == false){
            checkBox[i].checked = true;}
        else{
            checkBox[i].checked = false;}
    }
}