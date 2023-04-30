#include "XmlFile.h"

bool XmlFile::isFileEmpty() {
    xml.Load(FILE_NAME);

    if (!xml.FindElem())
        return true;
    else
        return false;
}
