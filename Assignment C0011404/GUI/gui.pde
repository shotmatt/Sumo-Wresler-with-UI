/* =========================================================
 * ====                   WARNING                        ===
 * =========================================================
 * The code in this tab has been generated from the GUI form
 * designer and care should be taken when editing this file.
 * Only add/edit code inside the event handlers i.e. only
 * use lines between the matching comment tags. e.g.

 void myBtnEvents(GButton button) { //_CODE_:button1:12356:
     // It is safe to enter your event code here  
 } //_CODE_:button1:12356:
 
 * Do not rename this tab!
 * =========================================================
 */

public void textarea1_change1(GTextArea source, GEvent event) { //_CODE_:textarea1:653858:
  println("textarea1 - GTextArea >> GEvent." + event + " @ " + millis());
} //_CODE_:textarea1:653858:

public void button2_click1(GButton source, GEvent event) { //_CODE_:button2:308221:
  //println("button2 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("a");
  textarea1.appendText("\nSent 'a' to Zumo");
} //_CODE_:button2:308221:

public void button3_click1(GButton source, GEvent event) { //_CODE_:button3:604378:
  //println("button3 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("d");
  textarea1.appendText("\nSent 'd' to Zumo");
} //_CODE_:button3:604378:

public void button4_click1(GButton source, GEvent event) { //_CODE_:button4:348760:
  //println("button4 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("w");
  textarea1.appendText("\nSent 'w' to Zumo");
} //_CODE_:button4:348760:

public void button5_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("s");
  textarea1.appendText("\nSent 's' to Zumo");
} //_CODE_:button5:984108:

public void button6_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("1");
  textarea1.appendText("\nSent '1' to Zumo");
}

public void button7_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("2");
  textarea1.appendText("\nSent '1' to Zumo");
}

public void button8_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("l");
  textarea1.appendText("\nSent '1' to Zumo");
}

public void button9_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write(" ");
  textarea1.appendText("\nSent ' ' to Zumo");
}


// Create all the GUI controls. 
// autogenerated do not edit
public void createGUI(){
  G4P.messagesEnabled(false);
  G4P.setGlobalColorScheme(GCScheme.BLUE_SCHEME);
  G4P.setCursor(ARROW);
  surface.setTitle("Sketch Window");
  button2 = new GButton(this, 11, 169, 80, 30);
  button2.setText("Left");
  button2.setTextBold();
  button2.addEventHandler(this, "button2_click1");
  button3 = new GButton(this, 127, 171, 80, 31);
  button3.setText("Right");
  button3.setTextBold();
  button3.addEventHandler(this, "button3_click1");
  button4 = new GButton(this, 71, 121, 80, 30);
  button4.setText("Forward");
  button4.setTextBold();
  button4.addEventHandler(this, "button4_click1");
  button5 = new GButton(this, 69, 225, 80, 30);
  button5.setText("Back");
  button5.setTextBold();
  button5.addEventHandler(this, "button5_click1");
  button6 = new GButton(this, 100,19,60,40);
  button6.setText("Manual");
  button6.setTextBold();
  button6.addEventHandler(this, "button6_click1");
  button7 = new GButton(this, 200,19,60,40);
  button7.setText("Auto");
  button7.setTextBold();
  button7.addEventHandler(this, "button7_click1");
  button8 = new GButton(this, 300,19,60,40);
  button8.setText("Back");
  button8.setTextBold();
  button8.addEventHandler(this, "button8_click1");
  button9 = new GButton(this, 400,19,60,40);
  button9.setText("Start");
  button9.setTextBold();
  button9.addEventHandler(this, "button9_click1");
}

// Variable declarations 
// autogenerated do not edit
GTextArea textarea1; 
GButton button2; 
GButton button3; 
GButton button4; 
GButton button5; 
GButton button6;
GButton button7;
GButton button8;
GButton button9;
