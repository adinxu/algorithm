#ifndef FINDPATH_H_INCLUDED
#define FINDPATH_H_INCLUDED
//一级格点9个，二级格点25个
typedef struct
{
  unsigned char src;
  unsigned char des;
  unsigned char index;
  unsigned char pathlist[6];
}Path;
void FindPath();


#endif // FINDPATH_H_INCLUDED
