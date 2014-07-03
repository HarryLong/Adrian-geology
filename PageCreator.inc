<?php
require('PageData.inc');

class PageCreator{
	public $xml;
	function __construct($file)
	{
		if (file_exists($file)) {
		    $this->xml = simplexml_load_file($file);
		} else {
		    exit('Failed to open test.xml.');
		}
	}

	function parse()
	{
		$page_data = new PageData();
		/* PAGE DATA */
		$page_data->setName($this->xml->page_name);
		$page_data->setDefaultPic($this->xml->default_pic);

		$layers = array();
		/* PER LAYER DATA */
		foreach($this->xml->layers->layer as $layer_data)
		{
			// print("GOT HERE");
			$layer_obj = new Layer();
			$layer_obj->setId($layer_data->layer_id);
			$layer_obj->setName($layer_data->layer_name);
			$layer_obj->setPicture($layer_data->layer_picture);
			$layer_obj->setDescription($layer_data->layer_description);

			$thumbnails = array();
			foreach($layer_data->thumbnails->thumbnail as $thumbnail)
			{
				$thumbnail_obj = new Thumbnail();
				$thumbnail_obj->setPicture($thumbnail->picture);
				$thumbnail_obj->setFullScreenPicture($thumbnail->full_screen_picture);
				$thumbnail_obj->setDescription($thumbnail->decription);

				$thumbnails[] = $thumbnail_obj; // Append to array of subpictures
			}

			$layer_obj->setThumbnails($thumbnails);

			$layers[] = $layer_obj; // Append to array of subpictures
		}

		$page_data->setLayers($layers);

		return $page_data;
	}
}
?>