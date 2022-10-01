const initialState = {
  start: false,
  mini_secs: 0,
  seconds: 0,
  minutes: 0,
  hours: 0,
  pause: false,
  lap : []
};

const stopWatch = (state = initialState, action) => {
  switch (action.type) {
    case "START":
      return {
        ...state,
        start: !state.start,
        // minutes: state.minutes,
        // seconds: state.seconds,
        // hours: state.hours,
        // pause: state.pause,
        // lap: state.lap 
      };

      case "MINI_SECS":
        return {
          ...state,
          mini_secs: state.mini_secs+1
        }

    case "SECS":
      return {
        //...state do this
        ...state,
        // start: state.start,
        // minutes: state.minutes,
        seconds: state.seconds + 1,
        // hours: state.hours,
        // pause: state.pause,
        // lap: state.lap 
      };
    case "MINS":
      return {
        ...state,
        // start: state.start,
        minutes: state.minutes + 1,
        // seconds: state.seconds,
        // hours: state.hours,
        // pause: state.pause,
        // lap: state.lap 
      };

    case "HRS":
      return {
        ...state,
        // start: state.start,
        // minutes: state.minutes,
        // seconds: state.seconds,
        hours: state.hours + 1,
        // pause: state.pause,
        // lap: state.lap 
      };

      case "MINI_SEC_TO_ZERO":
      return{
        ...state,
        mini_secs: 0
      }

    case "SEC_TO_ZERO":
      return {
        ...state,
        // start: state.start,
        // minutes: state.minutes,
        seconds: 0,
        // hours: state.hours,
        // pause: state.pause,
        // lap: state.lap 
      };

    case "MIN_TO_ZERO":
      return {
        ...state,
        // start: state.start,
        minutes: 0,
        // seconds: state.seconds,
        // hours: state.hours ,
        // pause: state.pause,
        // lap: state.lap 
      };

    case "RESET":
      return {
        start: !state.start,
        mini_secs: 0,
        minutes: 0,
        seconds: 0,
        hours: 0,
        pause: !state.pause,
        lap: [] 
      };

    case "PAUSE":
      return {
        ...state,
        pause: !state.pause,
        
      };

    case "LAP":
      return {
        ...state,
         lap : [...state.lap ,action.laps] 
      };

    default:
      return state;
  }
};

export default stopWatch;
