
const input=document.getElementById("username");
input.addEventListener("input",function(){
    this.value=this.value.replace(/[0-9]/g,'');
});
