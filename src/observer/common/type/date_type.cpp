#include "common/type/date_type.h"
#include "common/lang/comparator.h"
#include "common/lang/exception.h"
#include "common/lang/sstream.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/value.h"
#include "common/lang/iomanip.h"
#include "common/time/datetime.h"
#include "common/sys/rc.h"
int DateType::compare(const Value &left,const Value &right) const
{
  ASSERT(left.attr_type()== AttrType::DATES && right.attr_type()== AttrType::DATES,"invalid type");
  return common::compare_int((void *)&left.value_.int_value_,(void *)&right.value_.int_value_);
}
RC DateType::set_value_from_str(Value &val, const string &data) const
{
   int year, month, day;

    if (sscanf(data.c_str(),"%d-%d-%d",  &year ,  &month ,  &day  )!= 3){

        return RC::INVALID_DATE_FORMAT;
    }
    if (is_invalid_date(year,month,day)){

        return RC::INVALID_DATE_FORMAT;
    }
    val.set_date(year, month,day);

    return RC::SUCCESS;
    
}
RC   DateType::to_string(const Value &val, string &result) const
{
    int year    =                  val.value_.int_value_ / 10000;
    int month   =                  val.value_.int_value_ % 10000/ 100;
    int day     =                  val.value_.int_value_ % 100;
    stringstream ss;
    ss << year << "-" << std::setfill('0') << std::setw(2) << month << "-" << std::setw(2) << day;
    result = ss.str();
    return RC::SUCCESS;
}