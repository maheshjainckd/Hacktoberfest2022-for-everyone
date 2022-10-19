function RandomrbgGenerator() {
  const r = Math.floor(Math.random() * 256);
  const g = Math.floor(Math.random() * 256);
  const b = Math.floor(Math.random() * 256);
  return [r, g, b];
}

function RGBOptionsGenerator(intial, mode = "easy") {
  console.log({ mode });
  let options = [];
  if (mode === "easy") {
    for (let i = 3; i--; ) {
      options.push(`rgb(${RandomrbgGenerator().join(",")})`);
    }
    options.push(`rgb(${intial.join(",")})`);
    return shuffleArray(options);
  } else {
    let i = 3;
    while (i-- > 0) {
      options.push(
        `rgb(${eval(
          `intial[0] ${
            Math.random() * 10 > 5 ? "+" : "-"
          } Math.floor(Math.random()*20)`,
        )},${eval(
          `intial[1] ${
            Math.random() * 10 > 5 ? "+" : "-"
          } Math.floor(Math.random()*20)`,
        )},${eval(
          `intial[2] ${
            Math.random() * 10 > 5 ? "+" : "-"
          } Math.floor(Math.random()*20)`,
        )})`,
      );
    }
    options.push(`rgb(${intial})`);
    console.log({ options });
    return shuffleArray(options);
  }
}
function exec() {
  const intial = RandomrbgGenerator();
  const rgbline = document.getElementById("RGBLine");
  console.log({ rgbline });
  rgbline.textContent = `rgb(${intial})`;
  const rgboptions = $(".RGBOptions").toArray();
  RGBOptionsGenerator(
    intial,
    document.getElementById("gameMode")?.getAttribute("value"),
  ).forEach((a, y) => {
    $(rgboptions[y]).removeAttr("disabled");
    $(rgboptions[y]).css("opacity", "1");
    $(rgboptions[y]).css("background-color", a);
  });
}
function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

$(document).ready(function () {
  exec();
});
$(document).click(function (event) {
  const target = event.target;
  console.log(target.getAttribute("class"));
  if (target.getAttribute("class") !== "RGBOptions") {
  } else {
    setTimeout(() => {
      const rgbline = document.getElementById("RGBLine").textContent;
      console.log({
        cond: target.style.backgroundColor.replaceAll(" ", "") === rgbline,
        tar: target.style.backgroundColor.replaceAll(" ", ""),
        rg: rgbline,
      });
      if (target.style.backgroundColor.replaceAll(" ", "") === rgbline) {
        alert("You Win!");
        exec();
      } else {
        alert("You Lose!");
        exec();
      }
    }, 1000);
  }
});
function checkResult() {
  const rgbline = document.getElementById("RGBLine").textContent;
  const rgboptions = $(".RGBOptions").toArray();
  rgboptions.forEach((a, y) => {
    console.log({ a: a.style.backgroundColor, rgbline });
    if (a.style.backgroundColor.replaceAll(" ", "") !== rgbline) {
      $(a).css("opacity", "0.5");
    }
    $(a).prop("disabled", true);
  });
}

$("#gameMode").click(function () {
  const value = $(this).attr("value") === "easy" ? "hard" : "easy";
  $(this).attr("value", value);
  $(".modeValue").text(value)
  exec();
});

$(".hintButton").click(function () {
  checkResult();
});

$(".resetButton").click(function () {
  exec();
});