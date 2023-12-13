var isBackgroundColorChanged = false;
//This variable is used to keep track of whether the 
//background color of the specified section has been changed
function changeBackgroundColor() {
    var section = document.getElementById('about');
    //retrieves the HTML element with the ID 'about', 
    //which is the section whose background color you want to change.

    //Toggle between two colors
    if (isBackgroundColorChanged) {
        //If the background color is changed,
        //revert to the original color
        section.style.backgroundColor = '';
    } else {
        //If the background color is not changed,
        //set it to the new color
        section.style.backgroundColor = 'lightblue';
        //sets new color
    }
    isBackgroundColorChanged = !isBackgroundColorChanged;
    //Toggles the state variable for the next click
}
function toggleVisibility() {
    var element = document.getElementById('skills');
    //retrieves the HTML element with the ID 'skills'
    element.style.display = (element.style.display === 'none') ? 'block' : 'none';
    //Toggles the visibility
}
function validateForm() {
    var name = document.getElementById('name').value;
    //holds the value in the name box
    var email = document.getElementById('email').value;
    //holds the email in the name box

    
    if (name === '' || email === '') {
        //check if name and email are not empty
        alert('Name and email are required fields.');
        //alert if name or email not filled
        return false; // Prevent form submission
    }
    if (!email.includes('@')) {
        //check if acutal email
        alert('Please enter a valid email address.');
        return false; // Prevent form submission
    }
    // If all validation passes, you can submit the form
    document.forms[0].submit();
}



var currentImage = 1; //starting image
var totalImages = 4; //self explanatory
var captions = [ //self explanatory
    "Picture of my mom, dad and me",
    "Picture of profile picture",
    "Picture of me kicking my oppoent in a sparing match",
    "Picture of a jumping strike in the red stripe patern"
];
function prevImage() {
    if (currentImage > 1) {//if not first image go back
        currentImage--;
    } else { //if first image go to last photo
        currentImage = totalImages;
    }
    updateImage(); 
}
function nextImage() {
    if (currentImage < totalImages) {//if current image isnt last image
        currentImage++;
    } else {//if current image is the last image go back to beggining
        currentImage = 1;
    }
    updateImage();
}
function updateImage() {
    var image = document.getElementById('sliderImage'); 
    var caption = document.getElementById('imageCaption');
    image.src = 'Picture(' + currentImage + ').png'; // Update with image filenames
    caption.innerHTML = captions[currentImage - 1]; // updates the captions
}
