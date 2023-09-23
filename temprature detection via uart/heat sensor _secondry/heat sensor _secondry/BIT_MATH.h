

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  SET_BIT(REG,BIT_NUM)            ((REG)|=(1<<(BIT_NUM)))
#define  CLEAR_BIT(REG,BIT_NUM)          ((REG)&=(~(1<<(BIT_NUM))))
#define  GET_BIT(REG,BIT_NUM)            (((REG)>>(BIT_NUM))&1)
#define  TOGGLE_BIT(REG,BIT_NUM)         ((REG) ^= (1>>(BIT_NUM)))


#define  IS_LOW(REG,BIT_NUM)     (!(((REG)>>(BIT_NUM))&1))
#define  IS_HIGH(REG,BIT_NUM)    (((REG)>>(BIT_NUM))&1)

#define  ROR(DATA,N)       ((DATA)=((DATA>>N)|((DATA)<<(8-(N)))))
#define  ROL(DATA,N)       ((DATA)=((DATA<<N)|((DATA)>>(8-(N)))))


#endif /* BIT_MATH_H_ */