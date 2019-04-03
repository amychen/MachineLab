void setup() {
  size(460, 500);
  frameRate(30);
}

void draw() {
  noStroke();
  background(104, 193, 200);
  fill(0);
  rectMode(CENTER);
  rect(width/2, height/2 + 30, 270, 300);
  
  //shirt
  fill(17, 103, 168);
  ellipse(width/2, height/2 + 285, 280, 300);
  
  //face and neck
  fill(239, 198, 107);
  ellipse(width/2, height/2 - 30, 250, 300);
  rect(width/2, height/2 + 130, 50, 50);
  arc(width/2, height/2 + 140, 90, 50, 0, PI);
  
  //eyes
  if (frameCount % 50 > 0 && frameCount % 50 < 50) {
    noStroke();
    fill(255);
    ellipse(width/2 - 55, height/2 - 50, 50, 20);
    ellipse(width/2 + 55, height/2 - 50, 50, 20);
    fill(102, 82, 34);
    ellipse(width/2 - 55, height/2 - 50, 20, 20);
    ellipse(width/2 + 55, height/2 - 50, 20, 20);
  } else {
    noFill();
    arc(width/2 - 55, height/2 - 70, 50, 10, 0, PI);
    arc(width/2 + 55, height/2 - 70, 50, 10, 0, PI);
  }
  
  //nose, arm line
  stroke(0);
  line(width/2, height/2, width/2, height/2 - 35);
  line(width/2 + 80, height/2 + 250, width/2 + 80, height/2 + 180);
  line(width/2 - 80, height/2 + 250, width/2 - 80, height/2 + 180);
  
  //eyebrow
  noFill();
  arc(width/2 - 55, height/2 - 70, 50, 10, PI, TWO_PI);
  arc(width/2 + 55, height/2 - 70, 50, 10, PI, TWO_PI);
  
  //mouth
  fill(0);
  arc(width/2, height/2 + 40, 100, 70, 0, PI);
  arc(width/2, height/2 -100, 270, 230, PI, TWO_PI);
  fill(229, 87, 87);
  arc(width/2, height/2 + 59, 80, 30, 0, PI);
}
