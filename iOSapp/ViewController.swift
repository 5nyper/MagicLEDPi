//
//  ViewController.swift
//  MagicLEDPi
//
//  Created by Vikaton on 12/10/15.
//  Copyright © 2015 Vikaton. All rights reserved.
//

import UIKit
import Alamofire

class ViewController: UIViewController {

    @IBOutlet weak var red: UIButton!
    @IBOutlet weak var green: UIButton!
    @IBOutlet weak var blue: UIButton!
    @IBOutlet weak var purple: UIButton!
    @IBOutlet weak var pink: UIButton!
    @IBOutlet weak var yellow: UIButton!
    override func viewDidLoad() {
        super.viewDidLoad()
        red.backgroundColor = UIColor.redColor()
        green.backgroundColor = UIColor.greenColor()
        blue.backgroundColor = UIColor.blueColor()
        purple.backgroundColor = UIColor.purpleColor()
        pink.backgroundColor = UIColor.magentaColor()
        yellow.backgroundColor = UIColor.yellowColor()
        
        let buttons: [UIButton] = [red,green,blue,purple,pink, yellow]
        for x in buttons {
            x.layer.cornerRadius = 50;
        }
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func onTouch(sender: UIButton!) {
        if sender.backgroundColor!.isEqual(UIColor.redColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=RED")
                .responseString { response in
                print(response.result.value)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.magentaColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=PINK")
                .responseString { response in
                    print(response.result.value)
            }
        }

        else if sender.backgroundColor!.isEqual(UIColor.greenColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=GREEN")
                .responseString { response in
                    print(response.result.value)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.blueColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=BLUE")
                .responseString { response in
                    print(response.result.value)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.purpleColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=1&color=PURPLE")
                .responseString { response in
                    print(response.result.value)
            }
        }


    }

}


