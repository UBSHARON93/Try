<!DOCTYPE html>
<html>
<body>

<div id="map_canvas" style="width:930px ;height:830px; border: 2px solid #3872ac;"></div>
<div id="info"></div>

<script>

function initialize() {
var geocoder;
var map;
var polygonArray = [];
    map = new google.maps.Map(
    document.getElementById("map_canvas"), {
        center: new google.maps.LatLng(50.566316, 9.719375),
        zoom: 19,
        mapTypeId: google.maps.MapTypeId.SATELLITE
    });
    var drawingManager = new google.maps.drawing.DrawingManager({
        drawingMode: google.maps.drawing.OverlayType.POLYLINE,
        drawingControl: true,
        drawingControlOptions: {
            position: google.maps.ControlPosition.TOP_CENTER,
            drawingModes: [
            google.maps.drawing.OverlayType.POLYLINE]
        },
    });
    console.log(drawingManager)
    drawingManager.setMap(map)

    google.maps.event.addListener(drawingManager, 'polylinecomplete', function (POLYLINE) {
        document.getElementById('info').innerHTML += "waypoints are:" + "<br>";
        for (var i = 0; i < POLYLINE.getPath().getLength(); i++) {
            document.getElementById('info').innerHTML += POLYLINE.getPath().getAt(i).toUrlValue(6) + "<br>";
        }
        polygonArray.push(POLYLINE);
    });

}
google.maps.event.addDomListener(window, "load", initialize);

</script>

<script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBu-916DdpKAjTmJNIgngS6HL_kDIKU0aU&callback=initialize&libraries=geometry,drawing&ext=.js"></script>

</body>
</html>
