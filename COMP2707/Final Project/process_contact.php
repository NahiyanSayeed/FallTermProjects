<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST["username"];
    $feedback = $_POST["feedback"];

    // Add your email address where you want to receive notifications
    // added test to the email so i dont acitidently send emails to csinfo and make them made
    $to = "CSINFO_TEST@uwindsor.ca";
    $subject = "New Contact Form Submission";
    $message = "Username: $username\n\nFeedback/Questions:\n$feedback";

    // Use mail() function to send the email
    mail($to, $subject, $message);

    // Redirect back to the contact page after submission
    header("Location: contact.html");
    exit;
}
?>
