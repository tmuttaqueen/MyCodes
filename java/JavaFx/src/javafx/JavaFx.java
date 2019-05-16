package javafx;

import javafx.application.Application;
import javafx.beans.binding.DoubleBinding;
import javafx.geometry.*;
import javafx.scene.*;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.scene.shape.Ellipse;
import javafx.stage.Stage;

public class JavaFx extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        /*Pane starLabel = labelOnStyledBackground(
                "Practical Principles of Plain and Perfect Pronunciation.",
                "star-label"
        );

        StackPane labelOnResizableBackground = labelOnStyledBackground(
                "Sally collects seashells on the seashore",
                "resizable-background"
        );
        labelOnResizableBackground.setPrefHeight(60);

        Label squareLabel = createLabel(
                "Betty Botter bought a bit of butter.",
                "square-label"
        );*/

        Label roundedLabel = createLabel(
                "Peter Piper pickedsdhsdhshshshshdfvd fewe twet wet wte t    wetwe    t 4t 34t t 4t 4t 4hdfj a peck of pickled peppers.",
                "rounded-label"
        );
        Label roundedLabel2 = createLabel(
                "ok",
                "rounded-label"
        );

        /*Node ellipticalLabel = createEllipticalLabel(
                "Round and round the rugged rock the ragged rascal ran.",
                "elliptical-label"
        );*/

        VBox root = new VBox(
                10,
                //starLabel,
                //labelOnResizableBackground,
                //squareLabel,
                roundedLabel,
                roundedLabel2
                //ellipticalLabel
        );
        //VBox.setVgrow(labelOnResizableBackground, Priority.SOMETIMES);
        root.setAlignment(Pos.TOP_CENTER);
        root.setPadding(new Insets(10));

        Scene scene = new Scene(root);
        scene.getStylesheets().add(
                JavaFx.class.getResource(
                        "label-styles.css"
                ).toExternalForm()
        );
        stage.setScene(scene);
        stage.setTitle("Resize me!");
        stage.show();
    }

    private Label createLabel(String text, String styleClass) {
        Label label = new Label(text);
        label.getStyleClass().add(styleClass);

        return label;
    }

    /*private StackPane labelOnStyledBackground(String text, String styleClass) {
        Label label = new Label(text);
        StackPane container = new StackPane(label);
        container.getStyleClass().add(styleClass);

        return container;
    }

    private Group createEllipticalLabel(String text, String styleClass) {
        final double INSET = 20;

        Label label = new Label(text);

        Ellipse ellipse = new Ellipse();
        ellipse.getStyleClass().add("ellipse");

        DoubleBinding halfWidth  = label.widthProperty().divide(2).add(INSET);
        DoubleBinding halfHeight = label.widthProperty().divide(4).add(INSET);

        ellipse.radiusXProperty().bind(halfWidth);
        ellipse.radiusYProperty().bind(halfHeight);

        ellipse.centerXProperty().bind(halfWidth);
        ellipse.centerYProperty().bind(halfHeight);

        label.setLayoutX(INSET);
        label.layoutYProperty().bind(halfHeight.subtract(label.heightProperty().divide(2)));

        Group group = new Group(ellipse, label);
        group.getStyleClass().add(styleClass);

        return group;
    }*/

    public static void main(String[] args) {
        Application.launch(args);
    }
} 