/** @type {HTMLCanvasElement} */
const canvas = document.getElementById('myCanvas');
const ctx = canvas.getContext('2d');

var SHAPE = {
    x: 0, y: 0,
    type: 'L',
    color: 'rgb(255,0,0)'
}

function displayShape(){

    ctx.fillStyle = SHAPE.color

    for(let y = 0; y<5; y++){
        for(let x = 0; x<5; x++){

            if(shapes[SHAPE.type][y][x] == 1) ctx.fillRect(SHAPE.x + x*100, SHAPE.y + y*100, 100, 100)
        }
    }
}
displayShape()
canvas.addEventListener('mousemove', (e) => {
    SHAPE.x = e.clientX, SHAPE.y = e.clientY - (window.innerHeight-window.innerWidth)/2
    console.log(SHAPE)
    ctx.clearRect(0,0,800,800)
    displayShape()
})