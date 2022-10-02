const submitBtn = document.querySelector('#submitBtn');
const clearBtn = document.querySelector('#clearBtn');

const videoList = [];

submitBtn.addEventListener('click', event => {
    event.preventDefault();
    const videoID = document.querySelector('#videoID').value;
    console.log(videoID);
    if(videoList.includes(videoID)) {
        return;
    }

    videoList.push(videoID);
    render();
});

clearBtn.addEventListener('click', event => {
    videoList.length = 0;

    render();
})

function render() {
    const videoContainer = document.querySelector('.video__container');
    videoContainer.innerHTML = '';

    videoList.forEach(video => {
        const videoElement = document.createElement('div');
        videoElement.classList.add('col');
        videoElement.setAttribute("id", video);

        const iFrame = document.createElement('iframe');
        iFrame.src = `https://www.youtube.com/embed/${video}`;
        iFrame.width = 420;
        iFrame.height = 315;

        videoElement.appendChild(iFrame);
        videoContainer.appendChild(videoElement);
    });
}