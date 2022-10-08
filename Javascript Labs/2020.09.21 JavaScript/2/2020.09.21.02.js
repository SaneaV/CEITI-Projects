	function calc()
	{
		let aValue = parseFloat(a.value);
		let bValue = parseFloat(b.value);
		let cValue = parseFloat(c.value);

		type.value = null;
		P.value = null;
		A.value = null;

		if((aValue<(bValue+cValue)) &&
			(bValue<(aValue+cValue)) &&
			(cValue<(bValue+bValue)))
		{
			if(aValue == bValue && aValue == cValue)
			{
				type.value = ("Равносторонний");
			}

			else if ((aValue == bValue && aValue != cValue) || 
				(aValue == cValue && aValue != bValue) || 
				(cValue == bValue && cValue != aValue))
			{
				type.value = ("Равнобедренный");
			}

			else if (Math.pow(aValue, 2) == (Math.pow(bValue, 2) + Math.pow(cValue, 2)) ||
				Math.pow(bValue, 2) == (Math.pow(aValue, 2) + Math.pow(cValue, 2)) ||
				Math.pow(cValue, 2) == (Math.pow(aValue, 2) + Math.pow(bValue, 2)))
			{
				type.value = ("Прямоугольный");
			}
			else 
			{
				type.value = ("Разносторонний");
			}

			P.value = calcP(aValue, bValue, cValue);
			A.value = calcA(aValue, bValue, cValue);
		}

		else 
			type.value = ("Не существует");

		function calcP(aValue, bValue, cValue)
		{
			return aValue + bValue + cValue;
		}

		function calcA(aValue, bValue, cValue)
		{
			let p = (aValue + bValue + cValue)/2;
			return (Math.sqrt(p*(p-aValue)*(p-bValue)*(p-cValue)));
		}
	}