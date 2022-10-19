var keyData = {
    a: {
        color: "purple",
        sound: new Howl({
            src: ['Sounds/A/bubbles.mp3']
        })
    },
    b: {
        color: "#d8fae0",
        sound: new Howl({
            src: ['Sounds/A/clay.mp3']
        })
    },
    c: {
        color: "#ef4a20",
        sound: new Howl({
            src: ['Sounds/A/confetti.mp3']
        })
    },
    d: {
        color: "#efed20",
        sound: new Howl({
            src: ['Sounds/A/corona.mp3']
        })
    },
    e: {
        color: "#4eef20",
        sound: new Howl({
            src: ['Sounds/A/dotted-spiral.mp3']
        })
    },
    f: {
        color: "#3120ef",
        sound: new Howl({
            src: ['Sounds/A/flash-1.mp3']
        })
    },
    g: {
        color: "#e720ef",
        sound: new Howl({
            src: ['Sounds/A/flash-2.mp3']
        })
    },
    h: {
        color: "#a0abfb",
        sound: new Howl({
            src: ['Sounds/A/flash-3.mp3']
        })
    },
    i: {
        color: "#a0fba2",
        sound: new Howl({
            src: ['Sounds/A/glimmer.mp3']
        })
    },
    j: {
        color: "#f5fba0",
        sound: new Howl({
            src: ['Sounds/A/moon.mp3']
        })
    },
    k: {
        color: "#fbc8a0",
        sound: new Howl({
            src: ['Sounds/A/pinwheel.mp3']
        })
    },
    l: {
        color: "#fbaba0",
        sound: new Howl({
            src: ['Sounds/A/piston-1.mp3']
        })
    },
    m: {
        color: "#665da5",
        sound: new Howl({
            src: ['Sounds/A/piston-2.mp3']
        })
    },
    n: {
        color: "#a55d87",
        sound: new Howl({
            src: ['Sounds/A/piston-3.mp3']
        })
    },
    o: {
        color: "#a55d5d",
        sound: new Howl({
            src: ['Sounds/A/prism-1.mp3']
        })
    },
    p: {
        color: "#5da5a1",
        sound: new Howl({
            src: ['Sounds/A/prism-2.mp3']
        })
    },
    q: {
        color: "#5da560",
        sound: new Howl({
            src: ['Sounds/A/prism-3.mp3']
        })
    },
    r: {
        color: "#cac9b0",
        sound: new Howl({
            src: ['Sounds/A/splits.mp3']
        })
    },
    s: {
        color: "#b0c9ca",
        sound: new Howl({
            src: ['Sounds/A/squiggle.mp3']
        })
    },
    t: {
        color: "#bab0ca",
        sound: new Howl({
            src: ['Sounds/A/strike.mp3']
        })
    },
    u: {
        color: "#9d0262",
        sound: new Howl({
            src: ['Sounds/A/suspension.mp3']
        })
    },
    v: {
        color: "#889d02",
        sound: new Howl({
            src: ['Sounds/A/timer.mp3']
        })
    },
    w: {
        color: "#c1d4ff",
        sound: new Howl({
            src: ['Sounds/A/ufo.mp3']
        })
    },
    x: {
        color: "#d5ffc1",
        sound: new Howl({
            src: ['Sounds/A/veil.mp3']
        })
    },
    y: {
        color: "#dbf3f3",
        sound: new Howl({
            src: ['Sounds/A/wipe.mp3']
        })
    },
    z: {
        color: "#f3dbdc",
        sound: new Howl({
            src: ['Sounds/A/zig-zag.mp3']
        })
    }
}
var circles = [];
function onKeyDown(event) {
    if (keyData[event.key]) {
        var maxPoint = new Point(view.size.width, view.size.height);
        var randomPoint = Point.random();
        var point = maxPoint * randomPoint;
        var newCircle = new Path.Circle(point, 500);
        newCircle.fillColor = keyData[event.key].color;
        keyData[event.key].sound.play();
        circles.push(newCircle);
    }
}
function onFrame(event) {
    for (var i = 0; i < circles.length; i++) {
        circles[i].fillColor.hue += 1;
        circles[i].scale(.9);
    }
}
circles.length=0;
// 