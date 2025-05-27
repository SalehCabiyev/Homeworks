document.querySelectorAll('.tooltip-btn').forEach(button=>{
    let tooltip;
    button.addEventListener('mouseenter',()=>{
        tooltip=document.createElement('div');
        tooltip.className='tooltip';
        tooltip.innerText=button.dataset.tooltip;
        button.appendChild(tooltip);
        

        requestAnimationFrame(()=>{
            const tooltipRect = tooltip.getBoundingClientRect()
            const buttonRect=button.getBoundingClientRect()
            const enoughSpaceAbove=buttonRect.top>tooltipRect.height+10;

            if(!enoughSpaceAbove){
                tooltip.style.top='100%';
                tooltip.style.transform='translate(-50%,8px)';
            }
            tooltip.classList.add('visible');


        });
        
        button.addEventListener('mouseleave',()=>{
            if(tooltip){
                tooltip.remove();
                tooltip=null;
            }
        });


    });
    
})
