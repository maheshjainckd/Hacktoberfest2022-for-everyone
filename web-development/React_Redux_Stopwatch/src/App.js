import React from "react";
import "./App.css";
import Start from "./components/buttons/Start";
import Lap from "./components/buttons/Lap";
import Reset from "./components/buttons/Reset";
import Pause from "./components/buttons/Pause";
import Timer from "./components/Timer";
import { useSelector } from "react-redux";
import LapNote from "./components/LapNote";

const App = () => {
  const myState = useSelector((state) => state.start);
  const pause = useSelector((state) => state.pause);
  const lap = useSelector((state) => state.lap);
  const start = useSelector((state) => state.start)

  const lapNotes = lap.slice(0).reverse().map((item) => (
    <LapNote key={item.key} lapNum={item.lapNum} seconds={item.seconds} minutes={item.minutes} hours={item.hours} mini_secs={item.mini_secs} />
  ));

  return (
    <React.Fragment>
      <h1 >STOPWATCH</h1>
      <Timer />
      <Start />
      {myState && pause && <Reset />}
      {!pause && start && <Lap />}
      <Pause />
      {lapNotes}
    </React.Fragment>
  );
};

export default App;
