import React from 'react'
import Carousel from 'better-react-carousel'

function OwlCarousel() {
    return (
        <>
            <Carousel cols={2} rows={1} gap={5} loop={true} autoplay={3000} scrollSnap={true} showDots={true} hideArrow={false}>
                <Carousel.Item>
                    <img width="100%" src="https://picsum.photos/800/600?random=1" alt='...' />
                </Carousel.Item>
                <Carousel.Item>
                    <img width="100%" src="https://picsum.photos/800/600?random=2" alt='...' />
                </Carousel.Item>
                <Carousel.Item>
                    <img width="100%" src="https://picsum.photos/800/600?random=3" alt='...' />
                </Carousel.Item>
                <Carousel.Item>
                    <img width="100%" src="https://picsum.photos/800/600?random=1" alt='...' />
                </Carousel.Item>
                {/* ... */}
            </Carousel>
        </>
    )
}

export default OwlCarousel
