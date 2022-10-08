function hideAllErrors(){

	let errors = document.querySelectorAll("[id$=error]");

	for (let elem of errors) {
		elem.style.visibility = "hidden"
	}
}

function check(){

	let form = document.forms.register;
	let submit = true;

	if(form.name.value.length == 0)
	{
		document.getElementById("name-error").style.visibility = "visible";
		submit = false;
	}
	else
		document.getElementById("name-error").style.visibility = "hidden";

	if(form.email.value.length == 0)
	{
		submit = false;
		invalidEmail()
	}
	else 
		document.getElementById("email-error").style.visibility = "hidden";

	let password = form.password.value;
	if(password.length<8 && password.length>4)
		document.getElementById("password-error").style.visibility = "hidden";
	else
	{
		document.getElementById("password-error").style.visibility = "visible";
		submit = false;
	}

	if(form['password-repeat'].value == password && password.length!=0)
		document.getElementById("password-repeat-error").style.visibility = "hidden";
	else{
		submit = false;
		document.getElementById("password-repeat-error").style.visibility = "visible";
	}

	if(form.ch1.checked || form.ch2.checked || form.ch3.checked)
		document.getElementById("checkbox-error").style.visibility = "hidden";
	else{
		submit = false;
		document.getElementById("checkbox-error").style.visibility = "visible";
	}

	let regex = /^(0?[1-9]|[12][0-9]|3[01])[\/\-](0?[1-9]|1[012])[\/\-]\d{4}$/

	if(form.dateBirth.value.match(regex))
		document.getElementById("dateBirth-error").style.visibility = "hidden";
	else
	{
		submit = false;
		document.getElementById("dateBirth-error").style.visibility = "visible";
	}

	if(form.country.value != "--Выберите одну--")
		document.getElementById("country-error").style.visibility = "hidden";
	else{
		submit = false;
		document.getElementById("country-error").style.visibility = "visible";
	}

	if(form.r1.checked || form.r2.checked || form.r3.checked)
		document.getElementById("radio-error").style.visibility = "hidden";
	else
	{
		submit = false;
		document.getElementById("radio-error").style.visibility = "visible";
	}


	if(submit)
	{
		form.removeEventListener('submit', preventDefault);
	}
	else
	{
		form.addEventListener('submit', preventDefault);
	}
}

function invalidEmail()
{
	document.getElementById("email-error").style.visibility = "visible";
}


function preventDefault(e) {
	e.preventDefault();
}
