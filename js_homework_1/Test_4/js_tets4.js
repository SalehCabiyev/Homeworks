const lights=["red","yellow","green"];
let current=0;
function switchLight(){
    lights.forEach(id=>document.getElementById(id).classList.remove("active"));
    current=(current+1)%lights.length;
    document.getElementById(lights[current]).classList.add("active");
}

