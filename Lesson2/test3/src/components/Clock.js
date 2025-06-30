import React, { useEffect, useState } from "react";
import "./Clock.css";

function Clock({label}){
    const [time,setTime]=useState(new Date());
    useEffect(()=>{ 
        const timer=setInterval(()=>setTime(new Date()),1000);
        return()=>clearInterval(timer);

    },[]);
    const formattedTime=time.toLocaleTimeString();

    return(<div className="clock">
        <h2>{label}</h2>
        <p className="time">{formattedTime}</p>

        
    </div>);
}
export default Clock;