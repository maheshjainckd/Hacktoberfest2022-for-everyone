const start = document.querySelector('.start')
const pause = document.querySelector('.pause')
const reset = document.querySelector('.reset')
const time  = document.querySelector('.result')

let [ms,sec,min,hrs] = [0,0,0,0]
let interval = null

function stopwatch(){
    ms++

    if(ms > 99){
        ms = 0
        sec++
    }
    if(sec > 59){
        sec = 0
        min++
    }
    if(min > 59){
        min = 0
        hrs++
    }

    let h   = hrs < 10 ? '0' + hrs : hrs
    let m   = min < 10 ? '0' + min : min
    let s   = sec < 10 ? '0' + sec : sec
    let mss = ms  < 10 ? '0' + ms  : ms

    time.textContent = `${h}:${m}:${s}:${mss}`
}

function startStopwatch(){
    if(interval !== null){
        clearInterval(interval)
    }

    interval = setInterval(stopwatch, 10)

    start.setAttribute('disabled', 'true')

    pause.removeAttribute('disabled')
    reset.removeAttribute('disabled')
}

function pauseStopwatch(){
    clearInterval(interval)

    start.removeAttribute('disabled')
    pause.setAttribute('disabled','true')
}

function resetStopwatch(){
    [ms,sec,min,hrs] = [0,0,0,0]
    time.textContent = `00:00:00:00`

    clearInterval(interval)
    start.removeAttribute('disabled')
    pause.setAttribute('disabled','true')
    reset.setAttribute('disabled','true')
}

pause.setAttribute('disabled', 'true')
reset.setAttribute('disabled', 'true')

start.addEventListener('click', startStopwatch)
pause.addEventListener('click', pauseStopwatch)
reset.addEventListener('click', resetStopwatch)