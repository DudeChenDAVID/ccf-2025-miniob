#include "common/type/data_type.h"
#include "common/type/attr_type.h"
#include "common/sys/rc.h"
#include "common/value.h"
#pragma once

class DateType : public DataType
{
  public:
  DateType():DataType(AttrType::DATES){}  
  
  virtual ~DateType()=default;

  int compare(const Value &left,const Value &right) const override;

  RC cast_to(const Value &val, AttrType type, Value &result) const override;
  
  RC set_value_from_str(Value &val,const string &data) const override;
  
  static bool is_invalid_date(int year,int month,int day);
  
  int cast_cost(AttrType type) override;
 
  RC to_string(const Value &val,string &result) const override;

  
    
  

};