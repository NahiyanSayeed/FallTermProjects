<?php
// Define the directory where uploaded files will be stored
$uploadDirectory = 'uploads/';

// Ensure the directory exists; create it if not
if (!file_exists($uploadDirectory)) {
    mkdir($uploadDirectory, 0755, true);
}

// Check if a file was uploaded
if (isset($_FILES['file'])) {
    $uploadedFile = $_FILES['file'];

    // Get the file name
    $fileName = basename($uploadedFile['name']);

    // Construct the full path to save the file
    $targetPath = $uploadDirectory . $fileName;

    // Check if the file already exists
    if (file_exists($targetPath)) {
        echo "File already exists. Please choose a different file.";
    } else {
        // Move the uploaded file to the target path
        if (move_uploaded_file($uploadedFile['tmp_name'], $targetPath)) {
            echo "File uploaded successfully.";
        } else {
            echo "Error uploading file. Please try again.";
        }
    }
} else {
    echo "No file uploaded.";
}
?>