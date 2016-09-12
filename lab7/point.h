// point.h
// ENCM 339 Lab7 - Fall 2015

#ifndef lab7_exe_D_lab7_exe_D_h
#define lab7_exe_D_lab7_exe_D_h

class Point{
public:
    Point();
    
    Point(double x, double y, int id);
    /* PROMISES: initialize x and y coordinates, and id of a point with the supplied
     *           values.
     */
    
    void setx(double value);
    /* PROMISES: sets value to the x-coordinate of a point.*/
    
    double getx()const;
    /* PROMISES: return the x coordinate of a point*/
    
    void sety(double value);
    /* PROMISES: sets value to the y-coordinate of a point.*/
    
    double gety()const;
    /* PROMISES: return the y-coordinate of a point*/
    
    void setid(int i);
    /* PROMISES: sets the id of the point to the value of i.*/
    
    int getid()const;
    /* PROMISES: return the id of a point*/
    
    double distance(const Point& other);
    /* REQUIRES: other refers to a point object 
     * PROMISES: calculates and returns the disance between this point and other
     *           point 
     */
private:
    double x;  // x-coordinate of point on a Cartesian plane
    double y;  // y-coordinate of point on a Cartesian plane
    int id;
};

#endif
