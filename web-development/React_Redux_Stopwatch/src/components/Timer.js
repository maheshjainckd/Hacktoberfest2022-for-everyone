import React, { useEffect } from "react";
import { useSelector, useDispatch } from "react-redux";

const Timer = () => {
  //   let seconds = 0;
  //   let minutes = 0;
  //   let hours = 0;
  //   let [seconds, setSeconds] = useState(0);
  //  //const [minutes, setMinutes] = useState(0);
  //   const [hours, setHours] = useState(0);

  const dispatch = useDispatch();

  const start = useSelector((state) => state.start);
  const mini_secs = useSelector((state) => state.mini_secs);
  const minutes = useSelector((state) => state.minutes);
  const seconds = useSelector((state) => state.seconds);
  const hours = useSelector((state) => state.hours);
  const pause = useSelector((state) => state.pause);
  
  useEffect(() => {
    if (start) {
      const timer = setInterval(() => {
        //setSeconds((prev) => prev + 1);
        if(!pause){
        dispatch({ type: "MINI_SECS" });
        }

        if(mini_secs / 99 === 1){
          dispatch({type: "MINI_SEC_TO_ZERO"});
          dispatch({ type: "SECS" });

        

        if (seconds / 60 === 1) {
          //setSeconds(0);
          dispatch({ type: "SEC_TO_ZERO" });
          // setMinutes((prev) => prev + 1);
          dispatch({ type: "MINS" });
          //setMinutes(mins);

          if (minutes / 60 === 1) {
            // setMinutes(0);
            dispatch({ type: "MIN_TO_ZERO" });

            dispatch({ type: "HRS" });

            //setHours((prev) => prev + 1);
          }
        }
      }
      }, 10);

      return () => {
        window.clearInterval(timer);
      };
    }
  }, [seconds, minutes, start, hours, pause, mini_secs]);


  return (
    <div>
      <h1>{`${hours<10 ? '0'+hours : hours} : ${minutes<10 ? '0'+minutes : minutes} : ${seconds < 10 ? '0'+seconds : seconds } : ${mini_secs < 10 ? '0'+mini_secs: mini_secs}`}</h1>
    </div>
  );
};

export default Timer;
