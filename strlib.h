#ifndef STRLIB
#define STRLIB

// TODO :: make this pointer based and reduce pass-by-value copying
// TODO :: Relook at the trim_right logic and think about how to take advantage of .data, and .len when doing shit
// TODO :: rewrite str_append

// PLAN :: Other String Functions?

s8 str_append(s8 first, char * txt);
s8 str_trim_right_dirty(s8 first, char * txt);
s8 str_trim_right(s8 first, usize trm);
s8 str_trim_left(s8 first, usize trm);
s8 slice(s8 string, usize left, usize right);

// add reallocate logic plz
s8 str_append(s8 first, char * txt) {
  usize iter = strlen(first.data);

  for(iter; iter<first.len; iter++) {
    first.data[iter];
  }
  
  return first;
}

// chop off from end of string, but data still exists
s8 str_trim_right_dirty(s8 first, char * txt) {
  usize iter = strlen(txt);
  first.len = first.len - iter;  
  
  return first;
}

// allocate a new string instead of just changing the lenght in the type
s8 str_trim_right(s8 first, usize trm) {

  s8 newstr;

  usize j=0;
  usize new_end = first.len - trm;
  newstr.len = new_end;
  
  for(usize i=first.len; i>new_end; i--) {
    newstr.data[j] = first.data[i];
    j++;
  }

  return newstr;
}

// allocate new copy unless we include two pointers in s8 impl
// this is slightly more expensive but should happen rarely
s8 str_trim_left(s8 first, usize trm) {

  s8 newstr;
  usize j=0;

  newstr.len = first.len - trm;  
  for(usize i=trm; i<first.len; i++) {
    newstr.data[j] = first.data[i];
    j++;
  }

  return newstr;
}

s8 slice(s8 string, usize left, usize right) {
  printf("implement here");
}

#endif

