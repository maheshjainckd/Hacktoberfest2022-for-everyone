export const start = () => {
    return {
        type: "START"
    }
}

export const miniSecs = () => {
    return {
        type: "MINI_SECS"
    }
}

export const secs = () => {
    return {
        type: "SECS"
    }
}

export const mins = () => {
    return {
        type: "MINS"
    }
}

export const hrs = () => {
    return {
        type: "HRS"
    }
}

export const miniSecToZero = () => {
    return {
        type: "MINI_SEC_TO_ZERO"
    }
}

export const secToZero = () => {
    return {
        type: "SEC_TO_ZERO"
    }
}

export const minToZero = () => {
    return {
        type: "MIN_TO_ZERO"
    }
}

export const reset = () => {
    return {
        type: "RESET"
    }
}

export const pause = () => {
    return {
        type: "PAUSE"
    }
}

export const lap = (n) => {
    return {
        type: "LAP",
        payload: n
    }
}


