/** @type {HTMLCanvasElement} */
const canvas = document.getElementById('myCanvas');
const ctx = canvas.getContext('2d');

var FIELD = {
    size: 0,
    cellSize: 0
}
var SHAPE = {
    x: 0, y: 0,
    type: 'L',
    color: 'rgb(255,0,0)',
}
function resizeCanvas(){
    canvas.height = window.innerHeight
    canvas.width = window.innerWidth

    if(window.innerHeight > window.innerWidth){
        FIELD.size = window.innerWidth
        FIELD.cellSize = window.innerWidth/8
    }else{
        FIELD.size = window.innerHeight
        FIELD.cellSize = window.innerHeight/8
    }
}
function drawPlayingField(){
    ctx.fillStyle = 'rgba(120,80,120,0.4)'

    if(window.innerHeight > window.innerWidth){

        ctx.fillRect(0, window.innerHeight/2 - FIELD.size/2, FIELD.size, FIELD.size)
    }else{
        
        ctx.fillRect(window.innerWidth/2 - FIELD.size/2, 0, FIELD.size, FIELD.size)
    }
}

resizeCanvas()
window.addEventListener('resize', resizeCanvas)
function displayShape(){

    ctx.fillStyle = SHAPE.color
    ctx.lineWidth = 3

    for(let y = 0; y<5; y++){
        for(let x = 0; x<5; x++){

            if(shapes[SHAPE.type][y][x] == 1){

                ctx.fillRect(SHAPE.x + x*FIELD.cellSize, SHAPE.y + y*FIELD.cellSize, FIELD.cellSize, FIELD.cellSize)
                ctx.strokeRect(SHAPE.x + x*FIELD.cellSize, SHAPE.y + y*FIELD.cellSize, FIELD.cellSize, FIELD.cellSize)
        
            }
        }
    }
}
drawPlayingField()
displayShape()

canvas.addEventListener('mousemove', (e) => {
    SHAPE.x = e.clientX, SHAPE.y = e.clientY
    console.log(SHAPE)
    ctx.clearRect(0,0,canvas.width,canvas.height)
    drawPlayingField()
    displayShape()
})