const field = document.getElementById("field");
const ball = document.getElementById("ball");
const ballSize = 20;

field.addEventListener("click", function(event) {
  const fieldRect = field.getBoundingClientRect();
  let x = event.clientX - fieldRect.left - ballSize / 2;
  let y = event.clientY - fieldRect.top - ballSize / 2;

  const maxX = field.clientWidth -( ballSize);
  const maxY = field.clientHeight - (ballSize);

  x = Math.max(0, Math.min(x, maxX));
  y = Math.max(0, Math.min(y, maxY));

  ball.style.left = `${x}px`;
  ball.style.top = `${y}px`;
});
