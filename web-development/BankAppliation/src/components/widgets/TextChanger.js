import React from "react";
import TextTransition, { presets } from "react-text-transition";
import "../../styles/Text.css"
const TEXTS = [
    "SAVE",
    "INVEST",
    "GROW",
    "REDEEM"
];

function TextChanger() {
    const [index, setIndex] = React.useState(0);

    React.useEffect(() => {
        const intervalId = setInterval(() =>
            setIndex(index => index + 1),
            2000 
        );
        return () => clearTimeout(intervalId);
    }, []);
    return (
        <div className="text-container">
            <h1>
                <TextTransition
                    text={TEXTS[index % TEXTS.length]}
                    springConfig={presets.molasses}
                />
            </h1>
        </div>
    )
}

export default TextChanger
