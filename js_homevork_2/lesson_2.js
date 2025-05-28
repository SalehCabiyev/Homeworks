//test 1
function foo_1(num1,num2){
   let counter=0;
    if(num1<num2){
        counter=-1;
    }
    else if(num1>num2){
        counter=1;
    }
    return counter


}
console.log(foo_1(1,2));
console.log(foo_1(5,2));
console.log(foo_1(2,2));


//test 2
function factorial(num){
   let counter=1;
    for(let i=1; i<=num;i++){
        counter=counter*i
    }
    return counter
}

console.log(factorial(3));
//test3
function foo_3(num,num1,num2){
    return Number(`${num}${num1}${num2}`);
}
console.log(foo_3(1,2,3))
//test4
function getArea(num,num1){
    let area=0;
    if(num1===undefined){
        area=num*num;
    }
    else{ area=num*num1;}
   
    return area;
}

console.log(getArea(3,4));
console.log(getArea(3));
//test5
function isPerfectNumber(num){
    
    let counter=0;
    for(let i=1;i<num;i++){
        if(num%i==0){
            counter+=i;
        }
    }
    return counter===num;
    
}
console.log(isPerfectNumber (6));
//test6
function allperfectnumbers(num,num1){
    let perfectnumbers=[];
    for(let i=num;i<=num1;i++)
    {
        if(isPerfectNumber(i)){
            perfectnumbers.push(i);
        }

    }
    console.log(perfectnumbers);
    return perfectnumbers;
}
allperfectnumbers(5,200);
//test7
function time (hour,minutes=0,seconds=0){
const hh=String(hour).padStart(2,'0');
const mm=String(minutes).padStart(2,'0');
const ss=String(seconds).padStart(2,'0');
 console.log(`${hh}:${mm}:${ss}`);
}
time(11,2,33);
//test 8
function timeinseconds (hour,minutes=0,seconds=0){
    let ss=hour*3600+minutes*60+seconds;
     console.log(`${ss} ss`);
     return ss

}
timeinseconds(13,25,59);
//test9
function secondstotime(ss)
{
    const hour=Math.floor(ss/3600);
    const min=Math.floor((ss%3600)/60);
    const sec=ss%60;
    const hh=String(hour).padStart(2,'0');
    const mm=String(min).padStart(2,'0');
    const sss=String(sec).padStart(2,'0')
    return console.log(`${hh}:${mm}:${sss}`)
    
}
secondstotime(6666);
//test10
function timediference(hh,mm,ss,hh1,mm1,ss1){
let time=timeinseconds(hh,mm,ss);
let time2=timeinseconds(hh1,mm1,ss1);
let diference=time-time2
if(diference<0){diference=diference*-1}
return secondstotime(diference);
}
timediference(10,11,12,13,14,15)

