// for right angle trianlge
struct point {
  int x;
  int y;
};

bool rightAngle(const vector<point> &arr) {
  ll distance1 = (arr[1].x - arr[0].x) * (arr[1].x - arr[0].x) +
                 (arr[1].y - arr[0].y) * (arr[1].y - arr[0].y);

  ll distance2 = (arr[2].x - arr[1].x) * (arr[2].x - arr[1].x) +
                 (arr[2].y - arr[1].y) * (arr[2].y - arr[1].y);

  ll distance3 = (arr[2].x - arr[0].x) * (arr[2].x - arr[0].x) +
                 (arr[2].y - arr[0].y) * (arr[2].y - arr[0].y);

  // debug3(distance1, distance2, distance3);

  ll mx = max(distance1, max(distance2, distance3));
  ll mn = min(distance1, min(distance2, distance3));
  ll mid = distance1 + distance3 + distance2 - mx - mn;

  // debug3(mx, mn, mid);

  (mx == 0 or mn == 0 or mid == 0) return false;

  return (mx == (mn + mid));
}
