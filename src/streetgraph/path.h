/**
 * This code is part of libcity library.
 *
 * @file streetgraph/path.h
 * @date 23.03.2011
 * @author Radek Pazdera (xpazde00@stud.fit.vutbr.cz)
 *
 * @brief Path representation
 *
 * Says what path takes the road between two intersections.
 */

#ifndef _PATH_H_
#define _PATH_H_

#include <string>

#include "../geometry/linesegment.h"

class Point;
class Vector;
class Polygon;

class Path
{
  public:
    Path();
    Path(LineSegment const& line);

    Path(Path const& source);
    Path& operator=(Path const& source);

    ~Path();

    Point begining() const;
    Point end() const;

    void setBegining(Point const& begining);
    void setEnd(Point const& end);

    /**
      Extract vector that what direction would this
      path take if it should be expanded beyond the
      begining point.
     @note
       The direction is oposite to the direction of
       the path. Path goes from begining to end, this
       vector goes away from begining (or backwards).

     @return Normalized direction Vector.
     */
    Vector beginingDirectionVector();

    /**
      Extract vector that what direction would this
      path take if it should be expanded beyond the
      end point.
     @note
       The direction is same to the direction of
       the path. Path goes from begining to end.

     @return Normalized direction Vector.
     */
    Vector endDirectionVector();

    bool isInside(Polygon const& certainArea) const;

    bool goesThrough(Point const& certainPoint) const;
    LineSegment::Intersection crosses(Path const& anotherPath, Point* intersection);

    Point nearestPoint(Point const& point);
    double distance(Point const& point);

    double length();

    void shorten(Point const& newBegining, Point const& newEnd);

    std::string toString();
  private:
   LineSegment *representation;
};


#endif
