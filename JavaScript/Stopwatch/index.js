const { EventEmitter } = require('events');

class Stopwatch extends EventEmitter {
    start = 0;
    lastRecord = 0;
    endedAt = 0;
    records = [];
    disableLogs = false;

    constructor(disableLogs = false) {
        super();

        this.start = Date.now();
        this.lastRecord = this.start;
        this.disableLogs = disableLogs;
    }

    record() {
        if (this.endedAt !== 0) throw new Error("This stop watch is ended");

        const recordedAt = Date.now(),
            timeInterval = recordedAt - this.lastRecord

        this.records.push({
            recordedAt,
            timeInterval
        });

        this.emit("record", {
            recordedAt,
            timeInterval
        });

        if (!this.disableLogs) console.log(`Record ${this.records.length}. Interval: ${timeInterval}\tRecorded At: ${recordedAt}`);
    }

    end() {
        this.end = Date.now();

        this.emit("end", this.toJSON());
    }

    toJSON() {
        return {
            startedAt: this.start,
            endedAt: this.endedAt,
            ended: this.endedAt !== 0,
            records: this.records
        }
    }
}

const watch = new Stopwatch();

watch.record();

const int1 = setInterval(watch.record.bind(watch), 3000);

setTimeout(() => {
    clearInterval(int1);

    watch.end();
}, 10000);

const int2 = setInterval(async () => {
    await new Promise(res => setTimeout(res, Math.floor(Math.random() * (2000 - 100) + 100)));

    watch.record();
}, 1000);

setTimeout(() => clearInterval(int2), 7000);

watch.on('end', (data) => console.log(data));