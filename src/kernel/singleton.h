#pragma once

#define SINGLETON(_class_name_) \
    static _class_name_ & getInstance() \
    {\
        static _class_name_ instance;\
        return instance;\
    }
