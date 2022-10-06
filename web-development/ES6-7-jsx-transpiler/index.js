/**  @jsx h */
// 👆 all jsx nodes will now run into h function (UwU)


function h(nodeName, attributes, ...args) {
    let children = args.length ? [].concat(...args) : null; 
    return { nodeName, attributes, children, }; 
}

function render(vnode) {
    // just pure text will be  returned just as it is
    if (vnode.split) return document.createTextNode(vnode);
    // create element with
    let n = document.createElement(vnode.nodeName);
    let a = vnode.attributes || {};
    // set values to attributes ...
    Object.keys(a).forEach(attribute => n.setAttribute(k, attribute[k]));
    
    // Now to manage children (big recursive problem )...
    (vnode.children || []).forEach(child => n.appendChild(render(child)));
    return vnode;
};

a = h("div", "name = null  hello = none ", 'hello world ', "hello world ");

let gg = render(a);



