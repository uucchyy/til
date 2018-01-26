// Render Multiple URLs to file

"use strict";
var RenderUrlsToFile, arrayOfUrls, system;

system = require("system");

/*
Render given urls
@param array of URLs to render
@param callbackPerUrl Function called after finishing each URL, including the last URL
@param callbackFinal Function called after finishing everything
*/
RenderUrlsToFile = function(urls, callbackPerUrl, callbackFinal) {
    var getFilename, next, page, retrieve, urlIndex, webpage;
    urlIndex = 0;
    webpage = require("webpage");
    page = null;
    getFilename = function() {
        return "rendermulti-" + urlIndex + ".png";
    };
    next = function(status, url) {
        page.close();
        //callbackPerUrl(status, url);
        return retrieve();
    };
    retrieve = function() {
        var url;
        if (urls.length > 0) {
            url = urls.shift();
            urlIndex++;
            page = webpage.create();
            
            page.viewportSize = { width : 1366 , height: 768 } ;
            page.settings.userAgent = "Phantom.js bot";
            
            var tablewidth,imgwidth,naturalwidth;
            
            return page.open(url, function(status) {
                var file;
                file = getFilename();
                if (status === "success") {
                    return window.setTimeout((function() {
                        page.render(file);
                        tablewidth = page.evaluate(function() { 
                            var table = document.getElementsByTagName('table');
                            var maxwidth = 0;
                            for(var i = 0; i < table.length; i++) {
                                if (maxwidth < table[i].scrollWidth) {
                                    maxwidth = table[i].scrollWidth;
                                }
                            }
                            return maxwidth; 
                        });
                        imgwidth = page.evaluate(function() { 
                            var img = document.getElementsByTagName('img');
                            var maxwidth = 0;
                            for(var i = 0; i < img.length; i++) {
                                if (maxwidth < img[i].scrollWidth) {
                                    maxwidth = img[i].scrollWidth;
                                }
                            }
                            return maxwidth; 
                        });
                        naturalwidth = page.evaluate(function() { 
                            var img = document.getElementsByTagName('img');
                            var maxwidth = 0;
                            for(var i = 0; i < img.length; i++) {
                                if (maxwidth < img[i].naturalWidth) {
                                    maxwidth = img[i].naturalWidth;
                                }
                            }
                            return maxwidth; 
                        });
                        console.log("\"" + url + "\"," + "\"" + tablewidth + "\"," + "\"" + imgwidth + "\"," + "\"" + naturalwidth + "\"");
                        return next(status, url);
                    }), 100);
                } else {
                    return next(status, url);
                }
            });
        } else {
            return callbackFinal();
        }
    };
    return retrieve();
};

arrayOfUrls = null;

if (system.args.length > 1) {
    arrayOfUrls = Array.prototype.slice.call(system.args, 1);
} else {
    arrayOfUrls = ["http://phantomjs.org/","http://phantomjs.org/documentation/","http://phantomjs.org/examples/"];
}

RenderUrlsToFile(arrayOfUrls, (function(status, url, file) {
    if (status !== "success") {
        return console.log("Unable to render '" + url + "'");
    } else {
        return console.log("Rendered '" + url + "' at '" + file + "'");
    }
}), function() {
    return phantom.exit();
});
