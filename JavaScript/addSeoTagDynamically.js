function addSEOTag(metadata) {
    const { title, meta, httpEquiv, links, og, twitter } = metadata;

    if(title) {
        document.title = title;
    }

    if(meta) {
        meta.map((meta) => {
            const metaRobots = document.createElement('meta');
            metaRobots.name = meta.name;
            metaRobots.content = meta.content;
            document.head.appendChild(metaRobots);
        })
    }
    
    if(httpEquiv) {
        httpEquiv.map((http_equiv) => {
            const httpEquivTag = document.createElement('meta');
            httpEquivTag.httpEquiv = http_equiv.name;
            httpEquivTag.content = http_equiv.content;
            document.head.appendChild(httpEquivTag);
        })
    }

    if(links) {
        links.map((link) => {
            const linkTag = document.createElement('link');
            linkTag.rel = link.name;
            linkTag.href = link.content;
            document.head.appendChild(linkTag);
        })
    }

    if(og) {
        og.map((og) => {
            const ogTag = document.createElement('meta');
            ogTag.setAttribute('property', `og:${og.name}`);
            ogTag.content = og.content;
            document.head.appendChild(ogTag);
        })
    }
    
    if(twitter) {
        twitter.map((twitter) => {
            const twitterTag = document.createElement('meta');
            twitterTag.setAttribute('property', `twitter:${twitter.name}`);
            twitterTag.content = twitter.content;
            document.head.appendChild(twitterTag);
        })
    }

    return document.head;
}

// Example

const data = {
    title: 'Hactoberfest 2022',
    meta: [{name: 'description', content: 'Hactoberfest 2022 ⚓'}, {name: 'author', content: 'hacktoberfest'}],
    httpEquiv:[{name: 'refresh', content: '30'}],
    links: [{name: 'stylesheet', content: 'styles.css'}],
    og:[{name: 'type', content: 'website'}, {name: 'url', content: 'http://example.com'}],
    twitter: [{name: 'type', content: 'website'}, {name: 'url', content: 'http://example.com'}],
}

console.log(addSEOTag(data));