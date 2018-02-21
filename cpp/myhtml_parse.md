### C向けのHTMLパーサー
https://github.com/lexborisov/myhtml

### インストール
```
# cd /usr/local/src/
# wget https://github.com/lexborisov/myhtml/archive/v4.0.4.tar.gz
# tar xvf v4.0.4.tar.gz 
# cd myhtml-4.0.4/
# make
# make install
```

### ビルド
```
$ gcc test.c -lm /usr/local/lib/libmyhtml.so -std=gnu99
```


```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <myhtml/api.h>

#include <time.h>
#include <sys/time.h>

#ifndef MyHTML_EXAMPLE_EXAMPLE_H
#define MyHTML_EXAMPLE_EXAMPLE_H

/* Format */
#ifdef _WIN32
    #define MyCORE_FMT_Z "%Iu"
#else
    #define MyCORE_FMT_Z "%zu"
#endif

#endif /* MyHTML_EXAMPLE_EXAMPLE_H */


struct res_html {
    char  *html;
    size_t size;
};

struct res_html load_html_file(const char* filename)
{
    FILE *fh = fopen(filename, "rb");
    if(fh == NULL) {
        fprintf(stderr, "Can't open html file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    if(fseek(fh, 0L, SEEK_END) != 0) {
        fprintf(stderr, "Can't set position (fseek) in file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    long size = ftell(fh);
    
    if(fseek(fh, 0L, SEEK_SET) != 0) {
        fprintf(stderr, "Can't set position (fseek) in file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    if(size <= 0) {
        fprintf(stderr, "Can't get file size or file is empty: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char *html = (char*)malloc(size + 1);
    if(html == NULL) {
        fprintf(stderr, "Can't allocate mem for html file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    size_t nread = fread(html, 1, size, fh);
    if (nread != size) {
        fprintf(stderr, "could not read %ld bytes (" MyCORE_FMT_Z " bytes done)\n", size, nread);
        exit(EXIT_FAILURE);
    }
    
    fclose(fh);
    
    struct res_html res = {html, (size_t)size};
    return res;
}

void print_node_attr(myhtml_tree_node_t *node)
{
    myhtml_tree_attr_t *attr = myhtml_node_attribute_first(node);
    
    while (attr) {
        const char *name = myhtml_attribute_key(attr, NULL);
        
        if(name) {
            printf(" %s", name);
            
            const char *value = myhtml_attribute_value(attr, NULL);
            
            if(value)
                printf("=\"%s\"", value);
        }
        
        attr = myhtml_attribute_next(attr);
    }
}

void print_tree(myhtml_tree_t* tree, myhtml_tree_node_t *node, size_t inc)
{
    while (node)
    {
        for(size_t i = 0; i < inc; i++)
            printf("\t");
        
        // print current element
        const char *tag_name = myhtml_tag_name_by_id(tree, myhtml_node_tag_id(node), NULL);
        
        if(tag_name)
            printf("<%s", tag_name);
        else
            // it can not be
            printf("<!something is wrong!");
        
        // print node attributes
        print_node_attr(node);
        
        if(myhtml_node_is_close_self(node))
            printf(" /");
        
        myhtml_tag_id_t tag_id = myhtml_node_tag_id(node);
        
        if(tag_id == MyHTML_TAG__TEXT || tag_id == MyHTML_TAG__COMMENT) {
            const char* node_text = myhtml_node_text(node, NULL);
            printf(">: %s\n", node_text);
        }
        else {
            printf(">\n");
        }
        
        // print children
        print_tree(tree, myhtml_node_child(node), (inc + 1));
        node = myhtml_node_next(node);
    }
}

int main(int argc, const char * argv[])
{
    struct timeval startTime, endTime, result;
    struct tm *time_st1, *time_st2;
    const char weekName[7][4] = {
        "Sun",
        "Mon",
        "Tue",
        "Wed",
        "Thu",
        "Fri",
        "Sat"
    };

    const char* path;
    
    if (argc == 2) {
        path = argv[1];
    }
    else {
        printf("Bad ARGV!\nUse: print_tree_high_level <path_to_html_file>\n");
        exit(EXIT_FAILURE);
    }
    struct res_html res = load_html_file(path);
 
    gettimeofday(&startTime, NULL);
 
    // basic init
    myhtml_t* myhtml = myhtml_create();
    myhtml_init(myhtml, MyHTML_OPTIONS_DEFAULT, 1, 0);
    
    // first tree init
    myhtml_tree_t* tree = myhtml_tree_create();
    myhtml_tree_init(tree, myhtml);
    
    // parse html
    myhtml_parse(tree, MyENCODING_UTF_8, res.html, res.size);
   
    gettimeofday(&endTime, NULL);
    time_st1 = localtime(&startTime.tv_sec);
    time_st2 = localtime(&endTime.tv_sec);
    printf("startTime : %d/%02d/%02d(%s) %02d:%02d:%02d.%06d\n", 
                time_st1->tm_year+1900,     
                time_st1->tm_mon+1,         
                time_st1->tm_mday,          
                weekName[time_st1->tm_wday],
                time_st1->tm_hour,          
                time_st1->tm_min,           
                time_st1->tm_sec,           
                startTime.tv_usec            
                );

    printf("endTime : %d/%02d/%02d(%s) %02d:%02d:%02d.%06d\n", 
                time_st2->tm_year+1900,     
                time_st2->tm_mon+1,         
                time_st2->tm_mday,          
                weekName[time_st2->tm_wday],
                time_st2->tm_hour,          
                time_st2->tm_min,           
                time_st2->tm_sec,           
                endTime.tv_usec            
                );

    timersub(&endTime, &startTime, &result);
    printf("処理時間 : %dms\n",result.tv_usec / 1000);
    

    // print result
    // or see serialization function with callback: myhtml_serialization_tree_callback
    mycore_string_raw_t str = {0};
    myhtml_serialization_tree_buffer(myhtml_tree_get_document(tree), &str);
//    printf("%s\n", str.data);

    myhtml_tree_node_t *node = myhtml_tree_get_document(tree);
  //  print_tree(tree, myhtml_node_child(node), 0);
    
    // release resources
    mycore_string_raw_destroy(&str, false);
    myhtml_tree_destroy(tree);
    myhtml_destroy(myhtml);
    
    return 0;
}
```
