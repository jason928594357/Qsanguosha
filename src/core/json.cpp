#include "json.h"

JsonDocument::JsonDocument()
    :valid(false)
{

}

JsonDocument::JsonDocument(const QVariant &var)
    :value(var), valid(true)
{
}
