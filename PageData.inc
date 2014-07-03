<?php
class PageData
{
	private $name, $defaultPic, $layers;

	function name()
	{
		return $this->name;
	}

	function defaultPic()
	{
		return $this->defaultPic;
	}

	function layers()
	{
		return $this->layers;
	}

	function setName($name)
	{
		$this->name = $name;
	}

	function setDefaultPic($defaultPic)
	{
		$this->defaultPic = $defaultPic;
	}

	function setLayers($layers)
	{
		$this->layers = $layers;
	}

	function printPageData()
	{
		print("Name: $this->name <br/>");
		print("Default picture: $this->defaultPic <br/>");
		foreach($this->layers as $layer)
		{
			print("*****LAYER*****<br/>");
			$layer->printLayer();
			print("***************<br/>");
		}
	}
}

class Layer
{
	private $id, $name, $picture, $description, $thumbnails;

	function name()
	{
		return $this->name;
	}

	function picture()
	{
		return $this->picture;
	}

	function description()
	{
		return $this->description;
	}

	function id()
	{
		return $this->id;
	}

	function thumbnails()
	{
		return $this->thumbnails;
	}

	function setId($id)
	{
		$this->id = $id;
	}

	function setName($name)
	{
		$this->name = $name;
	}

	function setPicture($picture)
	{
		$this->picture = $picture;
	}

	function setDescription($description)
	{
		$this->description = $description;
	}

	function setThumbnails($thumbnails)
	{
		$this->thumbnails = $thumbnails;
	}

	function printLayer()
	{
		print("    Layer id: $this->id <br/>");
		print("    Layer name: $this->name <br/>");
		print("    Layer picture: $this->picture <br/>");
		print("    Layer description: $this->description <br/>");
		foreach($this->thumbnails as $thumbnail)
		{
			print("    *****THUMBNAIL*****<br/>");
			$thumbnail->printDetailedPicture();
			print("    *********************<br/>");
		}
	}
}

class Thumbnail
{
	private $picture, $fullscreen_picture, $description;

	function picture()
	{
		return $this->picture;
	}

	function description()
	{
		return $this->description;
	}

	function fullscreen_picture()
	{
		return $this->fullscreen_picture;
	}

	function setPicture($picture)
	{
		$this->picture = $picture;
	}

	function setFullScreenPicture($fullscreen_picture)
	{
		$this->fullscreen_picture = $fullscreen_picture;
	}

	function setDescription($description)
	{
		$this->description = $description;
	}

	function printDetailedPicture()
	{
		print("        Picture:  $this->picture <br/>");
		print("        Description: $this->description <br/>");
	}
}

?>